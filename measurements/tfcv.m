classdef tfcv < matlab.System
    % Untitled Add summary here
    %
    % This template includes the minimum set of functions required
    % to define a System object with discrete state.

    % Public, tunable properties
    properties
    end

    properties(DiscreteState)
        status;
        cnt;
    end

    % Pre-computed constants
    properties(Access = private) 
    end

    methods(Access = protected)
        function setupImpl(obj)
            % Perform one-time calculations, such as computing constants
            obj.status = uint16(0);
            obj.cnt = uint16(0);
        end

        function status = stepImpl(obj,input, assert_lim, assert_vld, deassert_lim, deassert_vld)
            % Implement algorithm. Calculate y as a function of input u and
            % discrete states.
            
            if(~obj.status) %false to true
                if(input>=assert_lim)
                    obj.cnt = obj.cnt+1;
                    if(obj.cnt>=assert_vld)
                        obj.status = uint16(1);
                        obj.cnt = uint16(0);
                    end
                else
                    obj.cnt = uint16(0);
                end
            else %true to false
                if(input<deassert_lim)
                    obj.cnt = obj.cnt+1;
                    if(obj.cnt>=deassert_vld)
                        obj.status = uint16(0);
                        obj.cnt = uint16(0);
                    end
                else
                    obj.cnt = uint16(0);
                end
            end
            status = obj.status;
        end

        function resetImpl(obj)
            % Initialize / reset discrete-state properties
        end
    end
end