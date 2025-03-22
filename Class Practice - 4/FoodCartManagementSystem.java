// Main Class
class FoodItem
{
    String name;
    double price;
    int quantity;  
    String size;
    public FoodItem(String name, double price,int quantity){
        this.name=name;
        this.price=price;
        this.quantity=quantity;
    }
    void displayInfo()
    {
        System.out.println("Name: "+name+", Price: "+price+", Quantity: "+quantity);
    }
    void applyDiscount(double percentage)
    {
        price = ((100-percentage)/100)*price;
    }
    double getPrice(){
        return price;
    }
}
class Beverage extends FoodItem{
    String size;
    boolean hasIce;
    public Beverage(String name, double price,String size,int quantity){
        super(name,price,quantity);
        this.size=size;
    }
    public Beverage(String name, double price,boolean ice,int quantity){
        super(name,price,quantity);
        hasIce = ice;
    }
    void addIce(){
        hasIce = true;
    }
    void displayInfo(){
        System.out.println("Name: "+name+", Price: "+price+", Quantity: "+quantity);
        System.out.println("Size :"+size+", Ice: "+hasIce);

    }
}

class Snack extends FoodItem{
    boolean isSpicy;
    public Snack(String name, double price,boolean spicy,int quantity){
        super(name,price,quantity);
        isSpicy = spicy;
    }
    void toggleSpiciness(){
        isSpicy = true;
    }
    void displayInfo(){
        System.out.println("Name: "+name+", Price: "+price+", Quantity: "+quantity);
        System.out.println("Spicy :"+isSpicy);

    }

}
class Dessert extends FoodItem{
    int calories;
    public Dessert(String name, double price,int calories,int quantity){
        super(name,price,quantity);
        this.calories = calories;
    }
    void displayInfo(){
        System.out.println("Name: "+name+", Price: "+price+", Quantity: "+quantity);
        System.out.println("Calories: "+calories+"Kcal");

    }

}
class FoodCart{
    FoodItem foods[];
    int size;
    public FoodCart(){
        foods = new FoodItem[10];
        size = 0;
    }
    void addItem(FoodItem item){
        foods[size++] = item;
    }
    void showCart(){
        for(int i=0;i<size;i++){
            foods[i].displayInfo();
        }
    }
    double calculateTotal(){
        double total = 0;
        for(int i=0;i<size;i++){
            total= total+ foods[i].getPrice();
        }
        return total;
    }
}
public class FoodCartManagementSystem {
    public static void main(String[] args) {
        Beverage soda = new Beverage("Soda", 1.99, "Medium",2);
        Snack chips = new Snack("Chips", 2.49, true,1);
        Dessert cake = new Dessert("Chocolate Cake", 4.99, 300,1);

        FoodCart cart = new FoodCart();

        cart.addItem(soda);
        cart.addItem(chips);
        cart.addItem(cake);

        System.out.println("Initial Cart:");
        cart.showCart();

        soda.applyDiscount(10); // 10% off
        cake.applyDiscount(15); // 15% off

        System.out.println("Updated Cart After Discounts:");
        cart.showCart();

        double total = cart.calculateTotal();
        System.out.println("Total Price: $" + total);
    }
}


//Output

// Initial Cart:
// --- Food Cart Items ---
// Name: Soda, Price: $1.99, Quantity: 2
// Size: Medium, Ice: No Ice
// --------------------
// Name: Chips, Price: $2.49, Quantity: 1
// Spicy: Yes
// --------------------
// Name: Chocolate Cake, Price: $4.99, Quantity: 3
// Calories: 300 kcal
// --------------------

// Ice added to Soda
// Spiciness of Chips is now disabled
// Half serving applied to Chocolate Cake

// Updated Cart After Applying Unique Features and Discounts:
// --- Food Cart Items ---
// Name: Soda, Price: $1.79, Quantity: 2
// Size: Medium, Ice: Added
// --------------------
// Name: Chips, Price: $2.49, Quantity: 1
// Spicy: No
// --------------------
// Name: Chocolate Cake, Price: $2.12, Quantity: 1
// Calories: 300 kcal
// --------------------

// Total Price: $8.19