clc;
if exist('WeightAnalysis.xlsx','file')
    delete  WeightAnalysis.xlsx;
end
Ca=2.20131;
XA=6.12724;
Index=linspace(1,30,30);
Index=Index.';
Component={'Radar';'Electronic Equipment #1';'Avionics #1';'Electronic Equipment #2';'Avionics #2';'Battery x2';'Electronic Equipment #3';'Air Conditioning';'Wings';'Fuel Tank';'Engines x2';'Horizontal Tail';'APU';'Vertical Tail';'Fuselage';'Nose Landing Gear';'Main Landing Gear';'Furnishing';'Wings Hydraulic System';'Control System';'Deicing System';'Fuel (tanked fully)';'Pilots x2';'Crew'; 'Passengers Row 1';'Passengers Row 2';'Passengers Row 3';'Passengers Row 4';'Passengers Row 5';'Luggage'};
Mass=[25;40;35;40;35;80;40;60;910;130;1500;250;250;160;2550;40;100;500;420;245;65;6750;160;80;80;160;160;160;160;540];
xCG=[0;1.415;3.232;4.940;3.232;10.833;4.940;9.381;6.014;6.539;9.052;11.577;10.845;11.406;5.672;1.683;5.733;5.929;6.014;6.014;6.014;6.539;2.635;4.360;4.360;5.166;5.952;6.779;7.605;9.503];
yCG=[0.320;0.365;0.719;0.353;0.719;1.268;0.353;1.256;0.280;0.195;1.268;3.830;1.341;2.671;0.939;-0.548;-0.548;0.744;0.280;0.280;0.280;0.195;0.487;0.750;0.750;0.750;0.750;0.750;0.750;1.061];
T=table(Index,Component,Mass,xCG,yCG);
T.Properties.VariableUnits{'Mass'} = 'kg';
T.Properties.VariableUnits{'xCG'} = 'm';
T.Properties.VariableUnits{'yCG'} = 'm';
writetable(T, 'WeightAnalysis.xlsx');
Mx=T.xCG.*T.Mass;
My=T.yCG.*T.Mass;
XCG=sum(Mx)/sum(T.Mass);
YCG=sum(My)/sum(T.Mass);
MACCG=100*((XCG-(XA-0.25*Ca))/Ca);
disp(T);
fprintf('Center of Gravity in X-direction is:%f m\n', XCG );
fprintf('Center of Gravity in Y-direction is:%f m\n', YCG );
fprintf('\n' );
fprintf('Mean Aerodynamic Chord: %f m\n', Ca);
fprintf('X of MAC nose is:%f m\n', XA );
fprintf('Center of Gravity position in percent of MAC is:%f %%\n', MACCG );