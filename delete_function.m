function [] = delete_function()
%delete_function deletes data saved in Timer.txt, Timer.xlsx and in the workspace
%   At the moment it deletes all data but later it will be available to delete only one event or past events

%checking if there is any data to be deleted

    if (exist('Timer.txt','file')==0)

        clc;
        fprintf("No data saved\n");
        return;

    end

%checking user intention

    while true
    
            prompt = 'What do you want to delete? All data[all], Past Data[past]:\n ';
            str = input(prompt,'s');
            
            if (isempty(str))||(strcmp(str,'all')==0) && (strcmp(str,'past')==0)
            
                fprintf("Wrong command, please try again!\n");
                continue;
                 
            elseif (strcmp(str,'all')==1)
            
                prompt = 'Are you sure you want to delete? Yes[Y]/No[N]:\n ';
                str = input(prompt,'s');

                if (isempty(str))||(strcmp(str,'Y')==0) && (strcmp(str,'N')==0)

                    fprintf("Wrong command, please try again!\n");
                    continue;

                elseif (strcmp(str,'Y')==1)

                    clc;
                    clear;
                    delete Timer.xlsx;
                    delete Timer.txt;
                    break;

                elseif (strcmp(str,'N')==1)

                    clc;
                    break;

                end
                
            elseif (strcmp(str,'past')==1)    
                
                check_past();
                clc;
                break;
                
            end
            
    end
    
end

