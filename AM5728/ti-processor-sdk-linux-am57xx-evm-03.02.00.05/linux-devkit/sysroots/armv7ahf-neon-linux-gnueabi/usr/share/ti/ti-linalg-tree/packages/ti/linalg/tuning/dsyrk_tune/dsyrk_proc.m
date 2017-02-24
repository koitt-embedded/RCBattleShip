N=8;
K=8;
load mat_a_1.dat;
load mat_cdsp_1.dat;
load mat_carm_1.dat;
load mat_a_2.dat;
load mat_cdsp_2.dat;
load mat_carm_2.dat;

A1=reshape(mat_a_1,N,K);
Cdsp1=reshape(mat_cdsp_1,N,N);
Carm1=reshape(mat_carm_1,N,N);
A2=reshape(mat_a_2,N,K);
Cdsp2=reshape(mat_cdsp_2,N,N);
Carm2=reshape(mat_carm_2,N,N);

diff1=Cdsp1-Carm1;
diff2=Cdsp2-Carm2;

C=Cdsp1;
for i=1:N
    C(i,i)=1;
end
for i=1:N
    for k=1:N
        if k<i
            C(i,k)=0;
        end
    end
end

Cnew=0.7*A1*transpose(A1)+0.3*C;

diff3=Cnew-Cdsp2;
diff4=Cnew-Carm2;

