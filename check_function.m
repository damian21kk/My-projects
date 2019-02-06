function [] = check_function(T)
%check_function allows the user to check the saved data
%   This function allows the user to see all data, see the time remaining
%   to all events or to just a specific one chosen by him/her.

        while true

            prompt = 'What do you want to do? show events[show], check all events [all], check specific events[specific]: ';
            str = input(prompt,'s');

            if (isempty(str)) || (strcmp(str,’show’)==0) && (strcmp(str,’specific’)==0) && (strcmp(str,’all’)==0)

                clc;
                fprintf('Wrong command, please try again!\n');
                continue;

            elseif (strcmp(str,’show’)==1)
                
                disp(T);
                break;

            elseif (strcmp(str,’all’)==1)
                
               check_all(T);
               break;

            elseif (strcmp(str,’specific’)==1)

               check_specific(T);
               break;

            elseif (strcmp(str,’all’)==1)

               check_all(T);
               break;

            end

        end
    
end

