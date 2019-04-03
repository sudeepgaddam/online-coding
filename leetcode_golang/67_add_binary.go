func addBinary(a string, b string) string {
    var (
        res string
        carry  int
    )
    i,j:= len(a)-1, len(b)-1
    for ;(i>=0 || j>=0 || carry!=0);i,j=i-1,j-1 {
        var x = 0
        var y = 0
        if i>=0 && a[i] == '1' {
            x = 1
        }
        if j >= 0 && b[j] == '1' {
            y = 1
        }
        var curval = x + y
        var rem = (curval + carry)%2
        carry = (curval + carry)/2

        res = strconv.Itoa(rem)  + res
    }
    return res
}
