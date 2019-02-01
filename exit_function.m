function [choice] = exit_function()
%UNTITLED2 Summary of this function goes here
%   Detailed explanation goes here
        while true
            prompt = 'Are you sure you want to exit? Yes[Y]/No[N]:\n ';
            str = input(prompt,'s');
            if (isempty(str))||(str~='Y') && (str~='N')
                fprintf("Wrong command, please try again!\n");
                continue;
            elseif str=='Y'
                clc;
                choice=true;
                break;
            elseif str=='N'
                choice=false;
                break;
            end
        end
end

