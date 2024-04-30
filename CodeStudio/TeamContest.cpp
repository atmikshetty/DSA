int team(vector <int> & skill, int n)
{
    // Brute Force O(N2)
    int count = 0;
    for(int i=0;i<n;i++){
        for(int j=1;j<n;j++){
            if(i<j && skill[i] > 2 * skill[j]){
                count++;
            }
        }
    }
    return count;
}
