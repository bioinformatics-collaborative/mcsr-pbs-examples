function b = isPrime(n)
fsr = floor(sqrt(n));
if mod(n,2) == 0
    b = 0;
    return
end
for i = 3:2:fsr
   if mod(n,i) == 0
       b = 0;
       return
   end
end
b = 1;
return
