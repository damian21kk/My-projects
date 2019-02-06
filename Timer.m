clear;
datetime.setDefaultFormats('default','yyyy-MM-dd hh:mm:ss');

if exist('Timer.txt','file')
  
    Told = readtable('Timer.txt');

end

while true

    prompt = 'What do you want to do? \nNew event[new], Check event[check], Save Data as [save], Delete data[delete], Exit the program[exit]:\n ';
    str = input(prompt,'s');

    if (isempty(str)) || (strcmp(str,’save’)==0) && (strcmp(str,’exit’)==0) && (strcmp(str,’check’)==0) && (strcmp(str,’new’)==0) && (strcmp(str,’delete’)==0)

        clc
        fprintf("Wrong command, please try again!\n");
        continue;
    
    elseif (strcmp(str,’exit’)==1)

        if exit_function()==true
  
            clear;
            return;
  
        else
  
            continue;
  
        end

    elseif (strcmp(str,’save’)==1) && (exist('Told','var')==0) && (exist('T','var')==0)
       
        clc;
        fprintf("No data to be saved!\n");
        
    elseif (strcmp(str,’save’)==1) && exist('Told','var')
       
        save_function(Told);
        clc;
        
    elseif (strcmp(str,’save’)==1) && (exist('Told','var')==0)
        
        save_function(T);
        clc;
        
    elseif (strcmp(str,’delete’)==1)

        delete_function();

    elseif (strcmp(str,’new’)==1) && exist('Timer.txt','file') && exist('Told','var')

        T=[Told;New_event(Told)];
        writetable(T,'Timer.txt');
        writetable(T,'Timer.xlsx');
        T = readtable('Timer.txt');
        clc;
        continue;

    elseif (strcmp(str,’new’)==1) && exist('Timer.txt','file') && (exist('Told','var')==0)

        T=[T;New_event(T)];
        writetable(T,'Timer.txt');
        writetable(T,'Timer.xlsx');
        T = readtable('Timer.txt');
        clc;
        continue;

    elseif (strcmp(str,’new’)==1) && (exist('Timer.txt','file')==0)

        T=new_table();
        writetable(T,'Timer.txt');
        writetable(T,'Timer.xlsx');
        T = readtable('Timer.txt');
        clc;
        continue;

    elseif (strcmp(str,’check’)==1) && (exist('Timer.txt','file')==0)

        clc;
        fprintf('No data saved\n');
        continue;

    elseif (strcmp(str,’check’)==1) && (exist('T','var')==0)

        check_function(Told);
        continue;

    elseif (strcmp(str,’check’)==1) && (exist('T','var')~=0)

        check_function(T);
        continue;
        
    end
    
end
