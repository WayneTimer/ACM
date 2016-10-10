program P1274;
var
  v,c,ma1,ma2:array[1..200] of integer;
  a:array[1..200,1..200] of integer;
  used:array[1..200] of boolean;
  n,m:integer;
procedure init;
  var
    i,k,q:integer;
  begin
    fillchar(v,sizeof(v),0);
    fillchar(c,sizeof(c),0);
    fillchar(ma1,sizeof(ma1),0);
    fillchar(ma2,sizeof(ma2),0);
    fillchar(a,sizeof(a),0);
    readln(n,m);
    for i:=1 to n do
      begin
        v[i]:=i;
        read(c[i]);
        for k:=1 to c[i] do
          begin
            read(q);
            a[i,k]:=q;
          end;
        readln;
      end;
  end;

function find(x:integer):boolean;
  var
    i,q:integer;
  begin
     used[x]:=true;
     for i:=1 to c[x] do
       begin
         q:=a[x,i];
         if (ma2[q]=0) or (not used[ma2[q]]) and (find(ma2[q])) then
           begin
             ma1[x]:=q;
             ma2[q]:=x;
             exit(true);
           end;
       end;
     find:=false;
  end;

procedure main;
  var
    i,s:integer;
  begin
    s:=0;
    for i:=1 to n do
      begin
        fillchar(used,sizeof(used),false);
        if find(i) then inc(s);
      end;
    writeln(s);
  end;

begin
  while not eof do
    begin
      init;
      main;
    end;
end.