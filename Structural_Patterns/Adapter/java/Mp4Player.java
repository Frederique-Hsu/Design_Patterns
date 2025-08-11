/**
 *  @file       Mp4Player.java
 *  @brief
 *
 */


import AdvancedMediaPlayer.*;


public class Mp4Player implements AdvancedMediaPlayer
{
    @override
    public void playVlc(String fileName)
    {
        // Nothing to do
    }

    @override
    public void playMp4(String fileName)
    {
        System.out.println("Playing mp4 file. Name: " + fileName);
    }
}
