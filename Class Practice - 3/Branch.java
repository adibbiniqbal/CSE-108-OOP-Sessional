public class Branch {

    private int id;
    private String name;
    private Account []  accounts;
    private int accountCount;
    private static Branch [] branches = new Branch[20];
    private static int branchCount = 0;
    // add your code here
    // there can be at most 20 branches  

     // you are not allowed to write any other constructor
    public Branch(int id, String name) {
        this.id = id;
        this.name = name;
        this.accounts = new Account[10];
        // add your code here
        branches[branchCount++] = this;

    }

    public void addAccount(Account a) {
        accounts[accountCount++] = a;
    }

    // add your code here
    public double getBranchBalance()
    {
        double b = 0;
        for(int i = 0; i < accountCount; i++)
        {
            b = b + accounts[i].getBalance();
        }
        return b;

    }
    public Account getMinBalanceAccount()
    {
        int idx = 0;
        double minbal = accounts[0].getBalance();
        for(int i=0;i<accountCount;i++)
        {
            if(accounts[i].getBalance()<minbal)
            {
                idx = i;
                minbal = accounts[i].getBalance();
            }
        }
        return accounts[idx];
    }

    public static void transferBalance(Account from, Account to, float bal)
    {
        if(from.getBalance()>bal)
        {
        from.removeBalance(bal);
        to.addBalance(bal);
        }
    }
    public static void printAllBranchesInfo()
    {
        for(int i=0;i<branchCount;i++)
        {
        System.out.println("Branch ID : "+(i+1)+" Branch Name : BR"+(i+1));
        
            for(int j=0;j<branches[i].accountCount;j++)
            {
                System.out.println("Account Number : "+(j+1)+" Name : "+branches[i].accounts[j].getCustomer()+" Balance : "+branches[i].accounts[j].getBalance());
            }
        }
    }
}
