function [choice] = exit_function()
%exit_function terminates the programme
%   The function checks if the user truly wants to exit the program and if he/she does than it sends the user "choice" back to the main script

        while true
        
            prompt = 'Are you sure you want to exit? Yes[Y]/No[N]:\n ';
            str = input(prompt,'s');
         
            if (isempty(str))|| (strcmp(str,'Y')==0) && (strcmp(str,'N')==0)
   
                fprintf("Wrong command, please try again!\n");
                continue;
   
            elseif (strcmp(str,'Y')==1)
   
                clc;
                choice=true;
                break;
   
            elseif (strcmp(str,'N')==1)
   
                choice=false;
                break;
   
             end
        
        end

end

