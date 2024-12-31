import controller.ControllerTelaLogin;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		/*Metodo para chamar a tela criado automaticamente, deixar aqui pro vai que não funfa
		 * EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					LoginGUI frame = new LoginGUI();
					frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
		 * 
		 */
		new ControllerTelaLogin();
	}

}
