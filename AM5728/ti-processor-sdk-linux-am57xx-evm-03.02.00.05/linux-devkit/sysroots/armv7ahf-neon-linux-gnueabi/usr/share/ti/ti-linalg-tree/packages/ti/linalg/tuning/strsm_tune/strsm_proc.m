M=1024;
N=8;
load mat_a.dat;
load mat_b.dat;
load mat_c.dat;
load mat_a2.dat;
load mat_b2.dat;
load mat_c2.dat;

A=reshape(mat_a,M,M);
B=reshape(mat_b,M,N);
C=reshape(mat_c,M,N);
A2=reshape(mat_a2,M,M);
B2=reshape(mat_b2,M,N);
C2=reshape(mat_c2,M,N);

diff=B-C;
diff2=B2-C2;

A3=A;

if 0
for i=1:M
    A3(i,i)=1;
end
for i=1:M
    for k=1:M
        if k<i
            A3(i,k)=0;
        end
    end
end
end

A3_inv=inv(A3);
B3=0.7*A3_inv*B;

diff3=B3-B2;
diff4=B3-C2;
