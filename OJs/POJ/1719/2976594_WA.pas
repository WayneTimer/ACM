program P1719;
var
  n,o,r,c,sum:integer;
  v:array[1..1000,1..2] of integer;
  ma1,ma2:array[1..1000] of integer;
  used:array[1..1000] of boolean;
procedure init;
  var
    i:integer;
  begin
    sum:=0;
    fillchar(ma1,sizeof(ma1),0);
    fillchar(ma2,sizeof(ma2),0);
    fillchar(used,sizeof(used),false);
    fillchar(v,sizeof(v),0);
    readln(r,c);
    for i:=1 to c do
      readln(v[i,1],v[i,2]);
  end;

function find(x:integer):boolean;
  var
    i,q:integer;
  begin
     for i:=1 to 2 do
       begin
         q:=v[x,i];
         if not used[q] then
           begin
             if ma2[q]=0 then
               begin
                 ma1[x]:=q;
                 ma2[q]:=x;
                 exit(true);
               end;
           end;
       end;
     for i:=1 to 2 do
       begin
         q:=v[x,i];
         if not used[q] then
           begin
             used[q]:=true;
             if find(ma2[q]) then
               begin
                 ma1[x]:=q;
                 ma2[q]:=x;
                 exit(true);
               end;
           end;
       end;
     find:=false;
  end;

procedure print;
  var
    i:integer;
  begin
    write(ma1[1]);
    for i:=2 to c do
      write(' ',ma1[i]);
  end;

procedure main;
  var
    i:integer;
  begin
    if r>c then writeln('NO')
      else
    begin
      for i:=1 to c do
        begin
          fillchar(used,sizeof(used),false);
          if find(i) then inc(sum);
        end;
      if sum=r then print else writeln('NO');
    end;
  end;

begin
  readln(n);
  for o:=1 to n do
    begin
      init;
      main;
    end;
end.