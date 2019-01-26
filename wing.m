ss=input('What is the stall speed?\n');
r=input('What is the range?\n');
wp=input('What is payload?\n');
b=input('What is the wingspan?\n');
vc=input('What is the cruise speed?\n');
ss=ss/3.6;
wto=1+wp;
L=0;
go=true;
while L<r
wer=((0.61-0.55)/(log10(10^4)-log10(10^5)))*(log10(wto)-log10(10^4))+0.61;
wf=wto-wto*wer-wp;
Q=wto*9.81;
P=Q;
czmax=1.84;
roa=1.225;
S=(2*Q)/(roa*ss*ss*czmax);
A=(b*b)/S;
e=0.7;
roc=0.412707;
cz=(2*Q)/(roc*(vc/3.6)*(vc/3.6)*S);
cxi=(cz*cz)/(pi*A*e);
cxmin=0.013;
cx=cxmin+cxi;
Px=0.5*roc*S*(vc/3.6)*(vc/3.6)*cx;
qe=0.045;
qt=Px*qe;
T=wf/qt;
L=vc*(T-(50/60));
if L<r
    wto=wto+100;
end
end
sprintf('Wing area is %d', S)