import java.util.*;

public class Ejercicio4{
    public static void main( String [] args){
        double i= 0;
        double seno=0,coseno=0,tangente=0, logaritmo=0,raizCuad=0;
        while(i < 87000000){
            seno += Math.sin(i);
            coseno += Math.cos(i);
            tangente += Math.tan(i);
            logaritmo += Math.log(i+1);
            raizCuad += Math.sqrt(i);
            i++;
        }
        System.out.println("Seno: " +seno);
        System.out.println("coseno: "+coseno);
        System.out.println("Tan: " + tangente);
        System.out.println("Logartimo: "+logaritmo);
        System.out.println("Raiz: "+raizCuad);
    }
}