# File          : map_site.py
# Description   : 
#
#
#


from abc import ABC, abstractmethod


class MapSite(ABC):
    @abstractmethod
    def enter(self):
        pass