import java.util.Random;

public class Ejercicio3{
    public static void main( String [] args){
        int n = new Random().nextInt(1000000);
        int c, cont=0;
        char [] cadena = new char[4];
        StringBuilder cadenota = new StringBuilder();
        Random r = new Random();
        for (int i=0; i < 87000000; i++){
            for (int  j=0; j<3; j++){
                //c = (new Random().nextInt(24)) + 65;
                //cadena[j] = (char)c;
                cadena[j] = (char)( r.nextInt(26)+'A');
            }
            cadena[3] = ' ';
            cadenota.append(cadena);
        }
        for(int i=0; i < cadenota.length(); i+=4){
            if(cadenota.charAt(i) == 'I' && cadenota.charAt(i+1) == 'P' && cadenota.charAt(i+2) == 'N')
                cont++;
        }
        System.out.println("Ocurrencias de IPN: " + cont);
    }
}