abstract class Animal {
    private String name;
    private int age;
    
    public Animal(String name, int age) {
        this.name = name;
        this.age = age;
    }
    abstract public boolean isLethalToAdultHumans();
    public String getName() {
        return name;
    }
    public int getAge() {
        return age;
    }
    abstract public String toString();
    
    // your code
}

// your code
abstract class Bird extends Animal
{
    public Bird(String name, int age)
    {
        super(name,age);
    }
    public boolean isLethalToAdultHumans()
    {
        return false;
    }
}
abstract class Mammal extends Animal
{
    String bloodType;
    public Mammal(String name, int age)
    {
        super(name,age);
        bloodType = "Warm blooded";
    }
    void printBloodType()
    {
        System.out.print(", Warm blooded!");
    }
    public boolean isLethalToAdultHumans()
    {
        return false;
    }
}
abstract class Reptile extends Animal
{
    String bloodType;
    public Reptile(String name, int age)
    {
        super(name,age);
    }
    public boolean isLethalToAdultHumans()
    {
        return true;
    }
}
abstract class Fish extends Animal
{
    String bloodType;
    public Fish(String name, int age)
    {
        super(name,age);
    }
    public boolean isLethalToAdultHumans()
    {
        return false;
    }
}
abstract class Arachnid extends Animal
{
    String bloodType;
    public Arachnid(String name, int age)
    {
        super(name,age);
    }
    public boolean isLethalToAdultHumans()
    {
        return true;
    }
}
class Albatross extends Bird
{
    public Albatross(String name, int age)
    {
        super(name,age);
    }
    public String toString()
    {
        return getName()+" is a Albatross, aged "+getAge()+" ";
    }
}
class Dog extends Mammal
{
    String bloodType;
    public Dog(String name, int age)
    {
        super(name,age);
    }
    public String toString()
    {
        return getName()+" is a Dog, aged "+getAge()+" ";
    }
}
class FruitBat extends Mammal
{
    String bloodType;
    public FruitBat(String name, int age)
    {
        super(name,age);
    }
    public String toString()
    {
        return getName()+" is a FruitBat, aged "+getAge()+" ";
    }
}
class EasternBrownSnake extends Reptile
{
    String bloodType;
    public EasternBrownSnake(String name, int age)
    {
        super(name,age);
    }
    public String toString()
    {
        return getName()+" is a EasternBrownSnake, aged "+getAge()+" ";
    }
}
class GreatWhiteShark extends Fish
{
    String bloodType;
    public GreatWhiteShark(String name, int age)
    {
        super(name,age);
    }
    public String toString()
    {
        return getName()+" is a GreatWhiteShark, aged "+getAge()+" ";
    }
}
class RedBackSpider extends Arachnid
{
    String bloodType;
    public RedBackSpider(String name, int age)
    {
        super(name,age);
    }
    
    public String toString()
    {
        return getName()+" is a RedBackSpider, aged "+getAge()+" ";
    }
}
class Platypus extends Mammal
{
    String bloodType;
    public Platypus(String name, int age)
    {
        super(name,age);
    }
    
    public String toString()
    {
        return getName()+" is a Platypus, aged "+getAge()+" ";
    }
}
class Human extends Mammal
{
    String bloodType;
    public Human(String name, int age)
    {
        super(name,age);
    }
    
    public String toString()
    {
        return getName()+" is a Human, aged "+getAge()+" ";
    }
}
public class Main {
    public static void main(String[] args) {
        Bird alex = new Albatross("Alex", 39);
        Mammal spot = new Dog("Spot", 7);
        Mammal fred = new FruitBat("Fred", 10);
        Reptile steph = new EasternBrownSnake("Steph", 12);
        Fish bruce = new GreatWhiteShark("Bruce", 40);
        Arachnid charlotte = new RedBackSpider("Charlotte", 1);
        Mammal perry = new Platypus("Perry", 5);
        Mammal bob = new Human("Bob", 20);

        Animal[] animals = { alex, spot, fred, steph, bruce, charlotte, perry, bob };
        for (Animal a : animals) {
            System.out.print(a);
            if (a instanceof Mammal) {
                ((Mammal) a).printBloodType();
            }
            if (a.isLethalToAdultHumans()) {
                System.out.print(", and it's lethal!");
            }
            System.out.println();
        }
        System.out.println();
    }
}

/* Output
Alexis a Albatross, aged 39
Spotis a Dog, aged 7, Warm-Blooded!
Fredis a FruitBat, aged 10, Warm-Blooded!
Stephis a EasternBrownSnake, aged 12, and it's lethal!
Bruceis a GreatWhiteShark, aged 40
Charlotteis a RedBackSpider, aged 1, and it's lethal!
Perryis a Platypus, aged 5, Warm-Blooded!
Bobis a Human, aged 20, Warm-Blooded!
*/