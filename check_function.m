function [] = check_function(T)
%UNTITLED Summary of this function goes here
%   Detailed explanation goes here

        while true

            prompt = 'What do you want to do? show events[show], check all events [all], check specific events[specific]: ';
            str = input(prompt,'s');

            if (isempty(str)) || (str ~= "show") && (str ~= "specific") && (str ~= "all")

                clc
                fprintf('Wrong command, please try again!\n')
                continue;

            elseif (str == "show")
                
                disp(T);
                break;

            elseif (str == "all")
                
               check_all(T);
               break;

            elseif (str == "specific")

               check_specific(T);
               break;

            elseif (str == "all")

               check_all(T);
               break;

            end

        end
    
end

