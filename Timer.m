clear
datetime.setDefaultFormats('default','yyyy-MM-dd hh:mm:ss');
if exist('Timer.txt','file')
    Told = readtable('Timer.txt');
end
while true
    prompt = 'What do you want to do? \nNew event[new], Check event[check], Exit the program[exit], Delete data[delete]:\n ';
    str = input(prompt,'s');
    if (str == "exit")
        clc;
        return;
    elseif (isempty(str)) || (str ~= "exit") && (str ~= "check") && (str ~= "new") && (str ~= "delete")
        clc
        fprintf("Wrong command, please try again!\n");
        continue;
    elseif (str == "delete") && exist('Timer.txt','file')
        delete Timer.txt;
        delete Timer.xlsx;
        clear;
        clc
        continue;
    elseif (str == "delete") && (exist('Timer.txt','file')==0)
        clc
        fprintf("No data saved\n");
        continue;
    elseif (str == "new") && exist('Timer.txt','file')
        T=[Told;New_event(Told)];
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
            prompt = 'What do you want to do? show events[show], check specific events[specific]: ';
            str = input(prompt,'s');
            if (isempty(str)) || (str ~= "show") && (str ~= "specific")
                clc
                fprintf('Wrong command, please try again!\n')
                continue;
            elseif (str == "show") && (exist('T','var')==0)
                disp(Told);
                break;
            elseif (str == "specific") && (exist('T','var')==0)
               check_specific(Told);
               break;
            elseif (str == "show") && (exist('T','var')~=0)
                disp(T);
                break;
            elseif (str == "specific") && (exist('T','var')~=0)
               check_specific(T);
               break;
            end
        end
        continue;
    end
end