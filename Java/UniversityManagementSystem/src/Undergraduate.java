public class Undergraduate extends Student {
    private Academic tutor;

    public Undergraduate(String login, String email) {
        super(login, email);
    }

    public Academic getTutor() {
        return tutor;
    }

    public void setTutor(Academic tutor) {
        this.tutor = tutor;
    }

    public String toString(){
        return "\nName: "+getName()+"\n"+
                "Login: "+getLogin()+"\n"+
                "Email: "+getEmail()+"\n"+
                "Tutor: "+tutor.getName()+"\n";
    }

}
