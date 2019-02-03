function [] = delete_function()
%delete_function deletes data saved in Timer.txt, Timer.xlsx and in the workspace
%   At the moment it deletes all data but later it will be available to delete only one event or past events

%checing if there is any data to be deleted

    if (exist('Timer.txt','file')==0)

        clc
        fprintf("No data saved\n");
        return;

    end

%checking user intention

    while true
    
            prompt = 'Are you sure you want to delete? Yes[Y]/No[N]:\n ';
            str = input(prompt,'s');
            
            if (isempty(str))||(str~='Y') && (str~='N')
            
                fprintf("Wrong command, please try again!\n");
                continue;
            
            elseif str=='Y'
            
                clc;
                clear;
                delete Timer.xlsx;
                delete Timer.txt;
                break;
            
            elseif str=='N'
            
                clc;
                break;
            
            end
            
    end
    
end

