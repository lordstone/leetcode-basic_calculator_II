class Solution {
public:
    int calculate(string s) {
        int ptr = 0;
        stack<int> op_stk, num_stk;
        int tmpsum = 0;
        bool flag = false;
        int op = 0; //1 for add, 2 for minus, 3 for multiplication, 4 for division
        while(ptr < s.length()){
            if(flag){
                if(op == 3){
                    num_stk.top() *= tmpsum;
                    tmpsum = 0;
                }else if(op == 4){
                    num_stk.top() /= tmpsum;
                    tmpsum = 0;
                }else if(op == 1 || op == 2){
                    num_stk.push(tmpsum);
                    op_stk.push(op);
                    tmpsum = 0;
                }
                op = 0;
            }
            if(s[ptr] >= '0' && s[ptr] <= '9'){
                tmpsum *= 10;
                tmpsum += s[ptr] - '0';
            }else if(s[ptr] == '*'){
                if(op != 0 && flag == false){
                    flag = true;
                    continue;
                }
                if(flag == true){
                    flag = false;
                }else{
                    num_stk.push(tmpsum);
                }
                tmpsum = 0;
                op = 3;
            }else if(s[ptr] == '/'){
                if(op != 0 && flag == false){
                    flag = true;
                    continue;
                }
                if(flag == true){
                    flag = false;
                }else{
                    num_stk.push(tmpsum);
                }
                tmpsum = 0;
                op = 4;
            }else if(s[ptr] == '+' || s[ptr] == '-'){
                if(op != 0 && flag == false){
                    flag = true;
                    continue;
                }
                if(flag == true){
                    flag = false;
                }else{
                    num_stk.push(tmpsum);
                }
                op = (s[ptr] == '+') ? 1:2;
                tmpsum = 0;
            }
            ptr ++;
        }//end while
        if(op >= 3){
            if(op == 3){
                num_stk.top() *= tmpsum;
            }else if(op == 4){
                num_stk.top() /= tmpsum;
            }
        }else if(op == 1 || op == 2){
            op_stk.push(op);
            num_stk.push(tmpsum);
        }else if(op == 0){
            return tmpsum;
        }
        if(num_stk.size() == 0) return 0;
        else if((num_stk.size() == 1)) return num_stk.top();
        else{
            int sum = 0;
            for(int i = op_stk.size() - 1; i >= 0; i --){
                int a = num_stk.top();
                num_stk.pop();
                if(op_stk.top() == 1) sum += a;
                else sum -= a;
                op_stk.pop();
            }
            sum += num_stk.top();
            return sum;
        }
        
    }
};
