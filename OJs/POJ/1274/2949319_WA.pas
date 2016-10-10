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
     for i:=1 to c[x] do
       begin
         q:=a[x,i];
         if not used[q] then
           begin
             used[q]:=true;
             if (ma1[q]=0) or find(ma1[q]) then
               begin
                 ma1[q]:=x;
                 ma2[x]:=q;
                 exit(true);
               end;
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
  init;
  main;
end.