A=[0,1,1,1;2,2,2,3;4,3,3,3;6,4,5,2];
B=[1;-1;1;4];
prover=det(A);

if(prover ~= 0)
    res2 = inv(A)*B;
end
disp("  Метод обратной матрицы")
disp(res2);
