program P1469;
var
  sum,n,p,t,o:integer;
  a:array[1..100,1..300] of integer;
  ma1:array[1..100] of integer;
  ma2,c:array[1..300] of integer;
  used:array[1..300] of boolean;
procedure init;
  var
    i,j:integer;
  begin
    fillchar(c,sizeof(c),0);
    fillchar(a,sizeof(a),0);
    fillchar(ma1,sizeof(ma1),0);
    fillchar(ma2,sizeof(ma2),0);
    fillchar(used,sizeof(used),false);
    sum:=0;
    readln(p,n);
    for i:=1 to p do
      begin
        read(c[i]);
        for j:=1 to c[i] do
          read(a[i,j]);
      end;
  end;

function find(x:integer):boolean;
  var
    i,q:integer;
  begin
     for i:=1 to c[x] do
       begin
         q:=a[x,i];
         if not used[q] then
           begin
             used[q]:=true;
             if (ma2[q]=0) or find(ma2[q]) then
               begin
                 ma1[x]:=q;
                 ma2[q]:=x;
                 exit(true);
               end;
           end;
       end;
     find:=false;
  end;

procedure main;
  var
    i:integer;
  begin
    for i:=1 to p do
      begin
        fillchar(used,sizeof(used),0);
        if find(i) then inc(sum);
      end;
    if sum=p then writeln('YES')
     else writeln('NO');
  end;

begin
  readln(t);
  for o:=1 to t do
    begin
      init;
      main;
    end;
end.