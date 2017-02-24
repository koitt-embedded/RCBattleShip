load mat_a.dat;
load mat_b.dat;
load mat_c.dat;
load mat_a2.dat;
load mat_b2.dat;
load mat_c2.dat;

A=reshape(mat_a,8,8);
B=reshape(mat_b,8,8);
C=reshape(mat_c,8,8);
A2=reshape(mat_a2,8,8);
B2=reshape(mat_b2,8,8);
C2=reshape(mat_c2,8,8);

diff=B-C;
diff2=B2-C2;

A3=A;
for i=1:8
    A3(i,i)=1;
end
for i=1:8
    for k=1:8
        if k<i
            A3(i,k)=0;
        end
    end
end

B3=0.7*A3*B;
