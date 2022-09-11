public class Student extends Person implements  Notifiable {


    private String login;
    private String email;

    public Student(String login, String email){
        super("Unknown");
        this.login=login;
        this.email=email;
    }

    public String getLogin() {
        return login;
    }

    public String getEmail() {
        return email;
    }

    public void setLogin(String login) {
        this.login = login;
    }

    public void setEmail(String email) {
        this.email = email;
    }


    @Override
    public void notify(String message) {
        System.out.println(getName()+"'s message: "+message);
    }

    public String toString(){
        return "\nName: "+getName()+"\n"+
                "Login: "+login+"\n"+
                "Email:"+email+"\n";

    }
}
