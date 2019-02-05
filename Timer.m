clear;
datetime.setDefaultFormats('default','yyyy-MM-dd hh:mm:ss');

if exist('Timer.txt','file')
  
    Told = readtable('Timer.txt');

end

while true

    prompt = 'What do you want to do? \nNew event[new], Check event[check], Save Data as [save], Delete data[delete], Exit the program[exit]:\n ';
    str = input(prompt,'s');

    if (isempty(str)) || (str ~= "save") && (str ~= "exit") && (str ~= "check") && (str ~= "new") && (str ~= "delete")

        clc
        fprintf("Wrong command, please try again!\n");
        continue;
    
    elseif (str == "exit")

        if exit_function()==true
  
            clear;
            return;
  
        else
  
            continue;
  
        end

    elseif (str == "save") && (exist('Told','var')==0) && (exist('T','var')==0)
       
        clc;
        fprintf("No data to be saved!\n");
        
    elseif (str == "save") && exist('Told','var')
       
        save_function(Told);
        clc;
        
    elseif(str == "save") && (exist('Told','var')==0)
        
        save_function(T);
        clc;
        
    elseif (str == "delete")

        delete_function();

    elseif (str == "new") && exist('Timer.txt','file') && exist('Told','var')

        T=[Told;New_event(Told)];
        writetable(T,'Timer.txt');
        writetable(T,'Timer.xlsx');
        T = readtable('Timer.txt');
        clc
        continue;

    elseif (str == "new") && exist('Timer.txt','file') && (exist('Told','var')==0)

        T=[T;New_event(T)];
        writetable(T,'Timer.txt');
        writetable(T,'Timer.xlsx');
        T = readtable('Timer.txt');
        clc
        continue;

    elseif (str == "new") && (exist('Timer.txt','file')==0)

        T=new_table();
        writetable(T,'Timer.txt');
        writetable(T,'Timer.xlsx');
        T = readtable('Timer.txt');
        clc
        continue;

    elseif (str == "check") && (exist('Timer.txt','file')==0)

        clc
        fprintf('No data saved\n');
        continue;

    elseif (str == "check") && exist('Timer.txt','file')

        while true

            prompt = 'What do you want to do? show events[show], check all events [all], check specific events[specific]: ';
            str = input(prompt,'s');

            if (isempty(str)) || (str ~= "show") && (str ~= "specific") && (str ~= "all")

                clc
                fprintf('Wrong command, please try again!\n')
                continue;

            elseif (str == "show") && (exist('T','var')==0)

                disp(Told);
                break;

            elseif (str == "specific") && (exist('T','var')==0)

               check_specific(Told);
               break;

            elseif (str == "all") && (exist('T','var')==0)

               check_all(Told);
               break;

            elseif (str == "show") && (exist('T','var')~=0)

                disp(T);
                break;

            elseif (str == "specific") && (exist('T','var')~=0)

               check_specific(T);
               break;

            elseif (str == "all") && (exist('T','var')~=0)

               check_all(T);
               break;

            end

        end

        continue;

    end

end