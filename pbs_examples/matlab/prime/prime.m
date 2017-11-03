matlabpool open 3

tic

p = [2];
parfor c = 3:3000000
    if isPrime(c) == 1
        p = [p c];
    end
end

toc

save('prime.mat', 'p');

matlabpool close
