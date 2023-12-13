Public Class Form1

    Private Sub Form1_Load(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MyBase.Load
        If SerialPort1.IsOpen Then
            SerialPort1.Close()
        End If
        For i As Integer = 0 To My.Computer.Ports.SerialPortNames.Count = 1
            ComboBox1.Items.Add(My.Computer.Ports.SerialPortNames(i))
        Next
    End Sub

    Private Sub Button1_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button1.Click
        Try
            With SerialPort1
                .PortName = ComboBox1.Text
                .BaudRate = 9600
                .Parity = IO.Ports.Parity.None
                .DataBits = 8
                .StopBits = IO.Ports.StopBits.One
            End With
            SerialPort1.Open()
            Label1.Text = "Kết nối tới" & "  " & ComboBox1.Text & " " & "thành công"

        Catch ex As Exception
            MsgBox(ex.ToString)
        End Try
    End Sub

    Private Sub SerialPort1_DataReceived(ByVal sender As Object, ByVal e As System.IO.Ports.SerialDataReceivedEventArgs) Handles SerialPort1.DataReceived
        Control.CheckForIllegalCrossThreadCalls = False
        Dim i As String
        i = SerialPort1.ReadExisting
        TextBox1.Text = Mid(i, 7, 5)
        TextBox2.Text = Mid(i, 12, 5)
        TextBox3.Text = Mid(i, 1, 5)
    End Sub

    Private Sub TextBox3_TextChanged(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles TextBox3.TextChanged

    End Sub

    Private Sub ComboBox1_SelectedIndexChanged(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles ComboBox1.SelectedIndexChanged

    End Sub
End Class
