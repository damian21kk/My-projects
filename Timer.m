clear
if exist('Timer.xlsx','file')
    Told = readtable('Timer.xlsx');
end
prompt = 'What do you want to do? New event[new], Check event[check]: ';
str = input(prompt,'s');
if (isempty(str)) || (str ~= "check") && (str ~= "new")
   return;
elseif (str == "new") && exist('Timer.xlsx','file')
    T=[Told;New_event(Told)];
    writetable(T,'Timer.xlsx');
elseif (str == "new") && (exist('Timer.xlsx','file')~=1)
    T=new_table();
    writetable(T,'Timer.xlsx');
elseif (str == "check") && (exist('Timer.xlsx','file')==0)
    return;
elseif (str == "check") && exist('Timer.xlsx','file')
    prompt = 'What do you want to do? show events[show], check specific events[specific]: ';
    str = input(prompt,'s');
    if (isempty(str)) || (str ~= "show") && (str ~= "specific")
        return;
    elseif (str == "show")
        disp(Told);
    elseif (str == "specific")
       check_specific(Told);
    end
end