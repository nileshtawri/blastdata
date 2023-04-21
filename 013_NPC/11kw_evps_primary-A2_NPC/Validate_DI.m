classdef Validate_DI < matlab.System
    % Untitled Add summary here
    %
    % This template includes the minimum set of functions required
    % to define a System object with discrete state.

    % Public, tunable properties
    properties
    end

    properties(DiscreteState)
        din_state;
        cnt;
    end

    % Pre-computed constants
    properties(Access = private)
    end

    methods(Access = protected)
        function setupImpl(obj)
            % Perform one-time calculations, such as computing constants
            obj.din_state = boolean(0);
            obj.cnt = uint16(0);
        end

        function status = stepImpl(obj, din, assert_logic, assert_dly, deassert_dly)
            % din -> Digital Input Signal from GPIO
            % assert_logic -> true - Assert if GPIO is High and Set State
            %                 false - Assert if GPIO is Low and Set State
            % assert_dly -> Delay in 1mS Counter to Assert Din Signal    
            % deassert_dly -> Delay in 1mS Counter to DeAssert Din Signal                 
            
            if(assert_logic) %if Assert Logic is True
                if(~obj.din_state) %Din State is Low
                    if(din == 1)
                        obj.cnt = obj.cnt+1;
                        if(obj.cnt>=assert_dly)
                            obj.din_state = boolean(1); %Assert Signal State
                            obj.cnt = uint16(0);
                        end
                    else
                        obj.cnt = uint16(0);
                    end
                else
                    if(din == 0)
                        obj.cnt = obj.cnt+1;
                        if(obj.cnt>=deassert_dly)
                            obj.din_state = boolean(0); %DeAssert Signal State
                            obj.cnt = uint16(0);
                        end
                    else
                        obj.cnt = uint16(0);
                    end
                end
            else %if Assert Logic is False
                if(~obj.din_state) %Din State is Low
                    if(din == 0)
                        obj.cnt = obj.cnt+1;
                        if(obj.cnt>=assert_dly)
                            obj.din_state = boolean(1); %Assert Signal State
                            obj.cnt = uint16(0);
                        end
                    else
                        obj.cnt = uint16(0);
                    end
                else
                    if(din == 1)
                        obj.cnt = obj.cnt+1;
                        if(obj.cnt>=deassert_dly)
                            obj.din_state = boolean(0); %DeAssert Signal State
                            obj.cnt = uint16(0);
                        end
                    else
                        obj.cnt = uint16(0);
                    end
                end
            end
            status = obj.din_state;
        end

        function resetImpl(obj)
            % Initialize / reset discrete-state properties
        end
    end
end