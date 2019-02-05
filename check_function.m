function [] = check_function(T)
%check_function allows the user to check the saved data
%   This function allows the user to see all data, see the time remaining
%   to all events or to just a specific one chosen by him/her.

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

