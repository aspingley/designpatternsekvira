import java.util.ArrayList;

interface Payment{
    // enum 
    //private double amount;
    //private String paymode;
    //private boolean status;
    public void pay(double amount);
}

class PayPalPayment implements Payment{
    public void pay(double amount){
        System.out.println("PayPalPayment. Amount = " + amount);
    }
}

class CreditCardPayment implements Payment{
    public void pay(double amount){
        System.out.println("CreditCardPayment. Amount = " + amount);
    }
}

class UPIPayment implements Payment{
    public void pay(double amount){
        System.out.println("UPIPayment. Amount = " + amount);
    }
}

class CartItem{
    private String description;
    private String orderDate;
    private String deliveryDate;
    private double cost;

    public void setCost(double c){
        cost = c;
    }

    public double getCost(){
        return cost;
    }
}

class Customer{
    private String name;
    private String address;
}

// ShoppingStrategy class represents the cart 
public class ShoppingStrategy{

    //Payment paymentMethod; // composition

    private ArrayList<CartItem> listItems = new ArrayList<CartItem>();

    public void addItem(CartItem item){
        listItems.add(item);
    }

    private double getTotalCost(){
        double total = 0.0;
        for(CartItem item: listItems){
            total += item.getCost();
        }
        return total;
    }

    public void checkout(Payment p){
        p.pay(this.getTotalCost()); // strategy
    }

    public static void main(String args[]){
        CartItem soap = new CartItem();
        soap.setCost(100);

        CartItem shampoo = new CartItem();
        shampoo.setCost(50);

        CartItem conditioner = new CartItem();
        conditioner.setCost(25);

        ShoppingStrategy cart = new ShoppingStrategy();
        cart.addItem(soap);
        cart.addItem(soap);
        cart.addItem(shampoo);
        cart.addItem(conditioner);
        cart.addItem(conditioner);
        cart.addItem(conditioner);

        //Payment paypal = new PayPalPayment();
        Payment upi = new UPIPayment();
        cart.checkout(upi);
    }
}