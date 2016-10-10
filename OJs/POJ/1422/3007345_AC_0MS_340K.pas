program P1422;
var
  n,s,e,o:integer;
  a:array[1..120,1..120] of boolean;
  used:array[1..120] of boolean;
  ma:array[1..120] of integer;
procedure init;
  var
    i,x,y:integer;
  begin
    fillchar(a,sizeof(a),false);
    read(s);
    read(e);
    for i:=1 to e do
      begin
        read(x,y);
        a[x,y]:=true;
      end;
  end;

function find(x:integer):boolean;
  var
    i:integer;
  begin
    if not used[x] then
      for i:=1 to s do
        if a[x,i] then
          begin
            used[x]:=true;
            if (ma[i]=0) or find(ma[i]) then
              begin
                ma[i]:=x;
                exit(true);
              end;
          end;
    find:=false;
  end;

procedure main;
  var
    i,sum:integer;
  begin
    sum:=0;
    fillchar(ma,sizeof(ma),0);
    for i:=1 to s do
      begin
        fillchar(used,sizeof(used),false);
        if find(i) then inc(sum);
      end;
    writeln(s-sum);
  end;

begin
  read(n);
  for o:=1 to n do
    begin
      init;
      main;
    end;
end.