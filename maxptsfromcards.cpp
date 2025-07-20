int function(int num,int k)
{
    int lsum=0,rsum=0,maxsum=0;
    for(int i=0;i<k;i++)
    {
        lsum=lsum+nums[i];
        maxsum=lsum;
        rightind=k-1;
        for(int j=k-1;j>=0;j--)
        {
            lsum=lsum-nums[i];
            rsum=rsum+nums[rightind];
            rightind=rightind-1;
            maxsum=max(maxsum,lsum+rsum);
        }
    }
    return maxsum;
}