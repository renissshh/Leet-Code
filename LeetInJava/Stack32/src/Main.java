import java.util.Deque;
import java.util.ArrayDeque;
class Solution{
    public int longestValidParentheses(String s){
        Deque<Integer> st = new ArrayDeque<>();
        st.push(-1);
        int maxLength =0;
        for(int i=0;i< s.length();i++){
            if(s.charAt(i)=='('){
                st.push(i);
            }else{
                st.pop();
                if(st.isEmpty()){
                    st.push(i);
                }else{
                    maxLength =Math.max(maxLength,i-st.peek());

                }
            }
        }
        return maxLength;
    }
}