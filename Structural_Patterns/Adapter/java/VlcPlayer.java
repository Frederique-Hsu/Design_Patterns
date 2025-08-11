/**
 *  @file       VlcPlayer.java
 *  @brief
 *
 */


import AdvancedMediaPlayer.*;

import System.*;

public class VlcPlayer implements AdvancedMediaPlayer
{
    @override
    public void playVlc(String fileNamem)
    {
        System.out.println("Playing vlc file. Name: " + fileName);
    }

    @override
    public void playMp4(String fileName)
    {
        // Nothing to do
    }
}
