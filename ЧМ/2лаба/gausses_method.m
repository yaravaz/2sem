A=[0,1,1,1;2,2,2,3;4,3,3,3;6,4,5,2];
B=[1;-1;1;4]; x=[0;0;0;0];

i=1;
k=1;
while(k<5)
    %поиск максимального
    max=abs(A(k,k));
    index=k;
    for i=(k+1):4
        if(abs(A(i,k)) > max)
            max=abs(A(i,k));
            index=i;
        end
    end
    %свап строк
    if(max<0.0001)
        desp("Решений бесконечное множество");
        return;
    end
    for j=1:4
        temp=A(k,j);
        A(k,j)=A(index,j);
        A(index,j)=temp;
    end
    temp=B(k);
    B(k)=B(index);
    B(index)=temp;
    disp(A);
    disp(B);
    %нормализация
    for i=k:4
        temp=A(i,k);
        if(abs(temp)<0.001)
            continue
        end
        for j=k:4
            A(i,j)=A(i,j)/temp;
        end
        B(i)=B(i)/temp;
        if(i==k)
            continue;
        end
        for j=1:4
            A(i,j)=A(i,j)-A(k,j);
            disp(A);
        end
        B(i)=B(i)-B(k);
        disp(A);
        disp(B);
    end
    k=k+1;
end
k=4;
%подсчёт корней
while(k>=1)
    x(k)=B(k);
    for i=1:k
        B(i)=B(i)-A(i,k)*x(k);
    end
    k=k-1;
end

disp(A);
disp(x);