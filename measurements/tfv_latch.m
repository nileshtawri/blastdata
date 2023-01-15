classdef tfv_latch < matlab.System
    % Untitled Add summary here
    %
    % This template includes the minimum set of functions required
    % to define a System object with discrete state.

    % Public, tunable properties
    properties
    end

    properties(DiscreteState)
        status;
        ref;
        now;
        cnt;
    end

    % Pre-computed constants
    properties(Access = private)
    end

    methods(Access = protected)
        function setupImpl(obj)
            % Perform one-time calculations, such as computing constants
            obj.status = uint16(0);
            obj.ref = uint16(0);
            obj.now = uint16(0);
            obj.cnt = uint16(0);
        end

        function status = stepImpl(obj,input, assert_lim, assert_vld, deassert_lim, deassert_vld, tmr)
            % Implement algorithm. Calculate y as a function of input u and
            % discrete states.
            if(assert_lim>deassert_lim) %assert above
                if(input>=assert_lim)
                    obj.now = tmr;
                    obj.cnt = obj.now - obj.ref;
                    if(obj.cnt>assert_vld)
                        obj.status = uint16(1);
                        obj.cnt = uint16(0);
                    end
                else
                    obj.ref = tmr;
                end
            elseif(assert_lim<deassert_lim) %assert under
                if(input<=assert_lim)
                    obj.now = tmr;
                    obj.cnt = obj.now - obj.ref;
                    if(obj.cnt>assert_vld)
                        obj.status = uint16(1);
                        obj.cnt = uint16(0);
                    end
                else
                    obj.ref = tmr;
                end
            else %invalid case
            end
            
            status = obj.status;
        end

        function resetImpl(obj)
            % Initialize / reset discrete-state properties
        end
    end
end