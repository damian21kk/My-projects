function [T] = check_past()
%UNTITLED4 Summary of this function goes here
%   Detailed explanation goes here
 
 
clc;
datetime.setDefaultFormats('default','yyyy-MM-dd hh:mm:ss');
 
T = readtable("Timer.txt");
n = size(T);
count = n(1);
to_be_deleted = [];
 
        for i = 1:count
                
                t1 = datetime('now');
                t2 = datetime(table2array(T(i,2)));
                dt = t2 - t1;
				sec = seconds(dt);
						
				if sec < 0
							
                    to_be_deleted=[to_be_deleted,table2array(T(i,1))];
						
                end
        
        end
        
        T.Properties.RowNames = T.Event;
        k = size(to_be_deleted);
        for i = k:k(2)
            
               row_name = char(to_be_deleted(1,i));
               T(row_name,:) = []; 
            
        end
        
delete Timer.txt;
delete Timer.xlsx;
writetable(T,"Timer.txt");
writetable(T,"Timer.xlsx");
 
end