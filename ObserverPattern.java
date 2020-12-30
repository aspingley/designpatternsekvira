import java.util.UUID;
import java.util.ArrayList;
import java.util.Iterator;

interface IObserver{
    public void update(String msg);
}

class ConcreteObserver implements IObserver{
    private UUID _identifier = UUID.randomUUID();
    public void update(String msg){
        System.out.println("Notification received in observer " + _identifier.toString() + " : " + msg);
    }
}

interface INotifier{
    public void register(IObserver o);
    public void remove(IObserver o);
    public void process();
}

class ConcreteNotifier implements INotifier{

    private ArrayList<IObserver> _list = new ArrayList<IObserver>();

    public void register(IObserver o){
        _list.add(o);
    }
    public void remove(IObserver o){
        _list.remove(o);
    }
    public void process(){
        Iterator<IObserver> itr = _list.iterator();
        while(itr.hasNext()){
            IObserver obs = itr.next();
            obs.update("Happy New Year");
        }
    }
}

public class ObserverPattern{
    public static void main(String args[]){

        IObserver ob1 = new ConcreteObserver();
        IObserver ob2 = new ConcreteObserver();
        IObserver ob3 = new ConcreteObserver();
        IObserver ob4 = new ConcreteObserver();

        INotifier n1 = new ConcreteNotifier();
        n1.register(ob1);
        
        n1.register(ob4);
        n1.register(ob3);
        n1.register(ob2);
        n1.register(ob3);

        n1.process();

        n1.remove(ob1);
        n1.remove(ob3);

        n1.process();

    }
}