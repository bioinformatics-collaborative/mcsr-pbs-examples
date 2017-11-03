% p's for Mersenne primes, where (2^p)-1 is Mp
p = [2 3 5 7 13 17 19 31 61 89 107 127 521 607 1279 2203 2281 3217 ...
     4253 4423 9689 9941 11213 19937 21701 23209 44497 86243 110503 ...
     132049 216091 756839 859433 1257787 1398269 2976221 3021377 ...
     6972593 13466917 20996011 24036583 25964951 30402457 32582657 ...
     37156667 42643801 43112609 57885161]; % All 48 of them

% Compute Mersenne primes given p
M = zeros(1, length(p));
for i = 1:length(p)
    M(i) = 2^p(i)-1;
end

% Compute pdiff and pdiffpercent
%pdiff = zeros(1, length(M));
pdiff(1) = M(1);
pdiffpercent(1) = 1;
for i = 2:length(M)
    pdiff(i) = M(i) - M(i-1)
    pdiffpercent(i) = pdiff(i) / M(i)
end

plot(pdiff)


