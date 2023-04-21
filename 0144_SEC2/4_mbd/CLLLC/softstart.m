classdef softstart < matlab.System
    % Untitled5 Add summary here
    %
    % This template includes the minimum set of functions required
    % to define a System object with discrete state.

    % Public, tunable properties
    properties
    end

    properties(DiscreteState)
        ref;
        eoss;
        diff;
    end

    % Pre-computed constants
    properties(Access = private)
    end

    methods(Access = protected)
        function setupImpl(obj)
            % Perform one-time calculations, such as computing constants
            obj.ref = uint16(0);
            obj.eoss = uint16(0);
            obj.diff = uint16(0);
        end

        function [ref, eoss] = stepImpl(obj, ref_target, intvl, input)
            % Implement algorithm. Calculate y as a function of input u and
            % discrete states.
            
            obj.diff = ref_target - input;
            
            if(obj.diff>intvl)
                obj.ref = input + intvl;
                obj.eoss = uint16(0);
            elseif(obj.diff<-intvl)
                obj.ref = input - intvl;
                obj.eoss = uint16(0);
            else
                obj.ref = ref_target;
                obj.eoss = uint16(1);
            end
            
            ref = uint16(obj.ref);
            eoss = uint16(obj.eoss);
        end

        function resetImpl(obj)
            % Initialize / reset discrete-state properties
        end
    end
end
