
interface Jump{
    public void doJump();
}

interface Weapon{
    public void showWeapon();
}

interface Sound{
    public void makeSound();
}
    
    
    abstract class Avatar{

        private Jump _jumpStrategy;
        private Weapon _weaponStrategy;
        private Sound _soundStrategy;        

        public Avatar(Jump j, Weapon w, Sound s){
            _jumpStrategy = j;
            _weaponStrategy = w;
            _soundStrategy = s;
        }

        public void doKick(){
            System.out.println("doKick abstract Avatar");
        }

        public void doPunch(){
            System.out.println("doPunch abstract Avatar");
        }
        
        public void showWeapon(){
            _weaponStrategy.showWeapon();
        }

        public void doJump(){
            _jumpStrategy.doJump();
        }

        public void makeSound(){
            _soundStrategy.makeSound();
        }
    }

    class LightningJump implements Jump{
        public void doJump(){
            System.out.println("LightningJump");
        }
    }

    class TornadoJump implements Jump{
        public void doJump(){
            System.out.println("TornadoJump");
        }
    }

    class RegularJump implements Jump{
        public void doJump(){
            System.out.println("RegularJump");
        }
    }

    class EmptyJump implements Jump{
        public void doJump(){
        }
    }

    class JaiShreeRam implements Sound{
        public void makeSound(){
            System.out.println("Sound JaiShreeRam");
        }
    }

    class EmptySound implements Sound{
        public void makeSound(){
            
        }
    }

    class MaceWeapon implements Weapon{
        public void showWeapon(){
            System.out.println("Mace weapon");
        }
    }

    class HammerWeapon implements Weapon{
        public void showWeapon(){
            System.out.println("Hammer weapon");
        }
    }

    class EmptyWeapon implements Weapon{
        public void showWeapon(){
            
        }
    }

    class Hanuman extends Avatar{
        public Hanuman(Jump j, Weapon w, Sound s){
            super(j, w, s);
        }
    }

    class BruceLee extends Avatar{
        public BruceLee(Jump j, Weapon w, Sound s){
            super(j, w, s);
        }
    }

    class Thor extends Avatar{
        public Thor(Jump j, Weapon w, Sound s){
            super(j, w, s);
        }
    }

    class Batman extends Avatar{
        public Batman(Jump j, Weapon w, Sound s){
            super(j, w, s);
        }
    }

public class Gamer{

        public static void main(String args[]){
            Jump j = new TornadoJump();
            Sound s = new JaiShreeRam();
            Weapon w = new MaceWeapon();
            Avatar hanuman = new Hanuman(j, w, s);
            hanuman.doJump();
            hanuman.doKick();
            hanuman.doPunch();
            hanuman.showWeapon();
            hanuman.makeSound();

            System.out.println("");

            Jump j1 = new RegularJump();
            Sound s1 = new EmptySound();
            Weapon w1 = new EmptyWeapon();
            Avatar batman = new Batman(j1, w1, s1);
            batman.doJump();
            batman.doKick();
            batman.doPunch();
            batman.showWeapon();
            batman.makeSound();

    }
}