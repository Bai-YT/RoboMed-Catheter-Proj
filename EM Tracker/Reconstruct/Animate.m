clear;
clc;
close all;
figure;                                                                

data = xlsread('1.xlsx');
Freq = 40;
pauseT = 1/Freq;

Tx1 = data(:, 9);
Ty1 = data(:, 10);
Tz1 = data(:, 11);
Tx2 = data(:, 101);
Ty2 = data(:, 102);
Tz2 = data(:, 103);
Tx3 = data(:, 193);
Ty3 = data(:, 194);
Tz3 = data(:, 195);

Tx1 = Tx1(Tx1>-1e4 & Tx1<1e4);
Tx2 = Tx2(Tx2>-1e4 & Tx2<1e4);
Tx3 = Tx3(Tx3>-1e4 & Tx3<1e4);
Ty1 = Ty1(Ty1>-1e4 & Ty1<1e4);
Ty2 = Ty2(Ty2>-1e4 & Ty2<1e4);
Ty3 = Ty3(Ty3>-1e4 & Ty3<1e4);
Tz1 = Tz1(Tz1>-1e4 & Tz1<1e4);
Tz2 = Tz2(Tz2>-1e4 & Tz2<1e4);
Tz3 = Tz3(Tz3>-1e4 & Tz3<1e4);

TxMin = min([min(Tx1), min(Tx2), min(Tx3)])-40;
TyMin = min([min(Ty1), min(Ty2), min(Ty3)])-40;
TzMin = min([min(Tz1), min(Tz2), min(Tz3)])-40;
TxMax = max([max(Tx1), max(Tx2), max(Tx3)])+40;
TyMax = max([max(Ty1), max(Ty2), max(Ty3)])+40;
TzMax = min([max(Tz1), max(Tz2), max(Tz3)])+40;

len = length(Tx1);
for k = 1:len
    plot3(Tx1(k), Ty1(k), Tz1(k), 'bo');
    hold on
    plot3(Tx2(k), Ty2(k), Tz2(k), 'ro');
    plot3(Tx3(k), Ty3(k), Tz3(k), 'go');
    xyz = [Tx1(k), Tx2(k), Tx3(k); Ty1(k), Ty2(k), Ty3(k); Tz1(k), Tz2(k), Tz3(k)];
    fnplt(cscvn(xyz), 'k', 1);
    hold off
    xlabel x
    ylabel y
    zlabel z
    xlim([TxMin, TxMax]);
    ylim([TyMin, TyMax])
    zlim([TzMin, TzMax]);
    drawnow;
    pause(pauseT);
end