function progress(){
	var txt = document.form.txt.value;
	var seq = txt.split("\n");
	var output="";
	for (var i = 0; i<20;i+=2)
	{
	    var result=calc(seq[i],seq[i+1]); //第i筆測資
		output=output+"<br>"+result;
	}
    document.getElementById('out').innerHTML= output;
}
function calc(str1,str2)
{
    /* 
       str1 : first polynomial
	   str2 : second polynomial
    */
    var len1 = str1.length;
    var len2 = str2.length;

	  var answer = "";
    /*----------------- Your Code Start-------------*/

    /* Hint: 
       var s = str1.substr(x,1) // the character s in the position x of str
    */
    
    var x={};
    var y={};
    var x1={};
    var y1={};
    var a=0;
    var b=0;
    var d="";
    var c=0;
    var z=0;
    var g=0;
    var h=0;
    x[0]="";
    y[0]="";
    var sum={};
    var sumx={};
    var sumy={};
    var sumz={};
    sum[0]="";
    sumx[0]="";
    sumy[0]="";
    sumz[0]="";
    if(str1[0]=="-")
      x1[0]=0;
    else
      x1[0]=1;
    for(var i=0;i<len1;i++)
    {
      if((str1[i]=="+"||str1[i]=="-")&&str1[i-1]!="^"&&i!=0)
      {
        g=1;
        a++;
        x[a]="";
        if(str1[i]=="-")
          x1[a]=0;
        else
          x1[a]=1;
      }
      else
      {
        g=0;
      }
      if(g==0)
      {
        if(i==0&&str1[i]=="-")
        {
          
        }
        else
          x[a]=x[a]+str1[i];
      }
    }
    b=0;
    if(str2[0]=="-")
      y1[b]=0;
    else
      y1[b]=1;
    for(var i=0;i<len2;i++)
    {
      
      if((str2[i]=="+"||str2[i]=="-")&&str2[i-1]!="^"&&i!=0)
      {
        g=1;
        b++;
        y[b]="";
        if(str2[i]=="-")
          y1[b]=0;
        else
          y1[b]=1;
      }
      else
      {
        g=0;
      }
      if(g==0)
      {
        if(i==0&&str2[i]=="-")
        {
          
        }
        else
          y[b]=y[b]+str2[i];  
      }
    }
    for(var i=0;i<=a;i++)
    {
      for(var j=0;j<=b;j++)
      {
        sumx[c]=parseInt(coex(x[i]))+parseInt(coex(y[j]));
        sumy[c]=parseInt(coey(x[i]))+parseInt(coey(y[j]));
        sumz[c]=parseInt(coez(x[i]))+parseInt(coez(y[j]));
        if((x1[i]==1&&y1[j]==1)||(x1[i]==0&&y1[j]==0))
          sum[c]=parseInt(n(x[i]))*parseInt(n(y[j]));
        else
          sum[c]=parseInt(n(x[i]))*parseInt(n(y[j]))*-1;
        sum[c]=parseInt(sum[c],10);
        c++;
      }
    }
    for(var i=0;i<c;i++)
    {
      for(var j=i;j<c;j++)
      {
        if(sumx[j]>sumx[i])
        {
          d=sumx[i];
          sumx[i]=sumx[j];
          sumx[j]=d;
          d=sumy[i];
          sumy[i]=sumy[j];
          sumy[j]=d;
          d=sumz[i];
          sumz[i]=sumz[j];
          sumz[j]=d;
          d=sum[i];
          sum[i]=sum[j];
          sum[j]=d;
        }
        if(sumx[j]==sumx[i])
        {
          if(sumy[j]>sumy[i])
          {
            d=sumx[i];
            sumx[i]=sumx[j];
            sumx[j]=d;
            d=sumy[i];
            sumy[i]=sumy[j];
            sumy[j]=d;
            d=sumz[i];
            sumz[i]=sumz[j];
            sumz[j]=d;
            d=sum[i];
            sum[i]=sum[j];
            sum[j]=d;
          }
          if(sumy[j]==sumy[i])
          {
            if(sumz[j]>sumz[i])
            {
              d=sumx[i];
              sumx[i]=sumx[j];
              sumx[j]=d;
              d=sumy[i];
              sumy[i]=sumy[j];
              sumy[j]=d;
              d=sumz[i];
              sumz[i]=sumz[j];
              sumz[j]=d;
              d=sum[i];
              sum[i]=sum[j];
              sum[j]=d;
            }
          }
        }
      }
    }
    for(var i=0;i<c;i++)
    {
      if(sumx[i]==sumx[i+1]&&sumy[i]==sumy[i+1]&&sumz[i]==sumz[i+1])
      {
        sum[i+1]+=sum[i];
      }
      else if(sum[i]!=0)
      {
        if(i!=0)
        {
          if(sum[i]>0)
            answer+="+";
        }
        if(sum[i]!=0)
        {
          if(sumx[i]!=0||sumy[i]!=0||sumz[i]!=0)
          {
            if(sum[i]==-1||sum[i]==1)
            {
              if(sum[i]==-1)
                answer+="-";
            }
            else
            {
              answer=answer+sum[i];
            }
          }
          else
           answer=answer+sum[i];
        }
        if(sumx[i]!=0)
        {
          if(sumx[i]<0)
            answer=answer+"-";
          answer=answer+"x";
          if(sumx[i]!=1)
          {
            answer=answer+"^"+sumx[i];
          }
        }
        if(sumy[i]!=0)
        {
          if(sumy[i]<0)
            answer=answer+"-";
          answer=answer+"y";
          if(sumy[i]!=1)
          {
            answer=answer+"^"+sumy[i];
          }
        }
        if(sumz[i]!=0)
        {
          if(sumz[i]<0)
            answer=answer+"-";
          answer=answer+"z";
          if(sumz[i]!=1)
          {
            answer=answer+"^"+sumz[i];
          }
        }
      }
    }
    console.log(answer);
    /*----------------- Your Code End --------------*/
	return answer;
}
function n(num)
{
  var sum="";
  var z=-1;
  parseInt(num,10);
  if(num[0]=="-")
  {
    for(var j=1;j<num.length;j++)
    {
      if(num[j]!="x"||num[j]!="y"||num[j]!="z")
        sum+=num[j];
      if(num[j]=="x"||num[j]=="y"||num[j]=="z")
      {
        if(j==1)
          return -1;
        else
        {
          parseInt(sum,10);
          return sum;
        }
        break;
      }
      else 
      {
        if(j==num.length-1)
        {
          parseInt(sum,10);
          return num[1];
        }
      }
    }
  }
  else
  {
    for(var j=0;j<num.length;j++)
    {
      if(num[j]!="x"||num[j]!="y"||num[j]!="z")
      sum=sum+num[j];
      if(num[j]=="x"||num[j]=="y"||num[j]=="z")
      {
        if(j===0)
          return 1;
        else
          {
            parseInt(sum,10);
            return sum;
          }
        break;
      }
      else 
      {
        if(j==num.length-1)
        {
          if(num.length==1)
            return num[0];
          else
          return sum;
        }
      }
    }
  }
}
function coex(num)
{
  var a="";
  a=0;
  parseInt(num,10);
  for(var i=0;i<num.length;i++)
  {
    if(num[i]=="x")
    {
      if(num[i+1]=="^")
      {
        if(num[i+2]=="-")
        {
          a+="-";
          a+=num[i+3];
        }
        else
          a=num[i+2];
      }
      else
        a=1;
    }
    
  }
  return a;
}
function coey(num)
{
  var a="";
  a=0;
  parseInt(num,10);
  for(var i=0;i<num.length;i++)
  {
    if(num[i]=="y")
    {
      if(num[i+1]=="^")
      {
        if(num[i+2]=="-")
        {
          a+="-";
          a+=num[i+3];
        }
        else
          a=num[i+2];
      }
      else
        a=1;
    }
  }
  return a;
}
function coez(num)
{
  var a="";
  a=0;
  for(var i=0;i<num.length;i++)
  {
    if(num[i]=="z")
    {
      if(num[i+1]=="^")
      {
        if(num[i+2]=="-")
        {
          a+="-";
          a+=num[i+3];
        }
        else
          a=num[i+2];
      }
      else
        a=1;
    }
  }
  return a;
}