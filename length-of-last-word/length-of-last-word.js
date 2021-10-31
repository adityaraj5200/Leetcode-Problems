/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLastWord = function(s) {
    let n=s.length, curr=0, flag=false;
    for(let i=n-1;i>=0;i--){
        if(s[i]===' '){
            if(flag === true)
                break;
        }
        else{
            curr++;
            flag = true;
        }
    }
    return curr;
};