int mySqrt(int x) {
if (x==0||x==1)
return x;
long left=1,right=x,mid,ans = 0;
while (left<=right){
mid=(left+right)/2;
if (mid*mid==x)
return mid;
else if (mid*mid<x){
ans = mid;
left = mid+1;
}
else
right = mid-1;
}
return ans;
}    