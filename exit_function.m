function [choice] = exit_function()
%exit_function terminates the programme
%   The function checks if the user truly wants to exit the program and if he/she does than it sends the user "choice" back to the main script

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

