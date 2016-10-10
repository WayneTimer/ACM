program P1325;
var
  ma:array[0..100] of integer;
  a:array[0..100,0..100] of boolean;
  used:array[0..100] of boolean;
  n,m,k:integer;
procedure init;
  var
    i,x,y,q:integer;
  begin
    for i:=0 to 100 do
      ma[i]:=-1;
    fillchar(a,sizeof(a),false);
    fillchar(used,sizeof(used),false);
    read(m,k);
    readln;
    for i:=1 to k do
      begin
        readln(q,x,y);
        a[x,y]:=true;
      end;
  end;

function find(x:integer):boolean;
  var
    i:integer;
  begin
    if not used[x] then
      for i:=0 to m-1 do
        if a[x,i] then
          begin
            used[x]:=true;
            if (ma[i]=-1) or find(ma[i]) then
              begin
                ma[i]:=x;
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
    for i:=0 to n-1 do
      begin
        fillchar(used,sizeof(used),false);
        if find(i) then inc(s);
      end;
    writeln(s);
  end;

begin
  read(n);
  while n<>0 do
    begin
      init;
      main;
      read(n);
    end;
end.